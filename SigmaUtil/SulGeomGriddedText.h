// SulGeomGriddedText.h

#ifndef __SULGEOMGRIDDEDTEXT_H__
#define __SULGEOMGRIDDEDTEXT_H__

#include "SulExport.h"
#include "SulTypes.h"
#include "SulString.h"
#include "SulGeomGrid.h"
#include "SulGeomGriddedTextUpdateCallback.h"
#include <osg/group>
#include <osgText/Text>

class SUL_EXPORT CSulGeomGriddedText : public osg::Group
{
public:
	enum EALIGN
	{
		ALIGN_LEFT,
		ALIGN_RIGHT
	};

public:
					CSulGeomGriddedText( sigma::uint32 cellCountX, sigma::uint32 cellCountY, sigma::uint32 cellW, sigma::uint32 cellH, sigma::uint32 viewW, sigma::uint32 viewH );

	void			noGrid();

	bool			setText( const CSulString& text, sigma::uint32 line, CSulGeomGriddedText::EALIGN eAlign );
	CSulString		getText( sigma::uint32 line );

	void			setPosition( sigma::int32 x, sigma::int32 y );
	void			setColor( osg::Vec4& color );

	void			blink( sigma::uint32 line, bool bBlink );

private:
	osg::ref_ptr<osg::MatrixTransform>	m_mt;
	
	sigma::uint32	m_cellCountX;
	sigma::uint32	m_cellCountY;
	sigma::uint32	m_cellW;
	sigma::uint32	m_cellH;

	typedef std::map< sigma::uint32, CSulString >		MAP_LINETEXT;
	MAP_LINETEXT										m_mapLineText;

	typedef std::vector< osg::ref_ptr<osgText::Text> >	VEC_TEXT;
	VEC_TEXT											m_vecText;				// only contains one letter

	osg::ref_ptr<CSulGeomGrid>							m_grid;

	typedef std::vector< osg::ref_ptr< CSulGeomGriddedTextUpdateCallback > >	VEC_CB;
	VEC_CB																		m_vecUpdateCallback;
};

#endif // __SULGEOMGRIDDEDTEXT_H__