/*
 * #%L
 * OME-BIOFORMATS C++ library for image IO.
 * Copyright © 2006 - 2015 Open Microscopy Environment:
 *   - Massachusetts Institute of Technology
 *   - National Institutes of Health
 *   - University of Dundee
 *   - Board of Regents of the University of Wisconsin-Madison
 *   - Glencoe Software, Inc.
 * %%
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of any organization.
 * #L%
 */

#ifndef OME_BIOFORMATS_TIFF_UTIL_H
#define OME_BIOFORMATS_TIFF_UTIL_H

#include <string>
#include <vector>

#include <ome/common/filesystem.h>

#include <ome/compat/memory.h>

#include <ome/bioformats/CoreMetadata.h>
#include <ome/bioformats/TileCoverage.h>
#include <ome/bioformats/tiff/TileInfo.h>
#include <ome/bioformats/tiff/Types.h>
#include <ome/bioformats/VariantPixelBuffer.h>

#include <ome/xml/model/enums/PixelType.h>

namespace ome
{
  namespace bioformats
  {
    namespace tiff
    {

      class TIFF;
      class IFD;

      /**
       * Create CoreMetadata from an IFD.
       *
       * @param ifd the IFD to use.
       * @returns the CoreMetadata.
       */
      ome::compat::shared_ptr<CoreMetadata>
      makeCoreMetadata(const IFD& ifd);

      /**
       * Get CoreMetadata from an IFD.
       *
       * @param ifd the IFD to use.
       * @param core the CoreMetadata to set.
       */
      void
      getCoreMetadata(const IFD&    ifd,
                      CoreMetadata& core);

      /**
       * Set CoreMetadata for an IFD.
       *
       * @param ifd the IFD to set.
       * @param core the CoreMetadata to use.
       */
      void
      setCoreMetadata(IFD&                ifd,
                      const CoreMetadata& core);

      /**
       * Range of IFDs for an image series.
       *
       * Note the range is half-open, with the end index being one
       * past the end of the range.
       */
      struct IFDRange
      {
        /// Filename of TIFF containing the IFDs.
        boost::filesystem::path filename;
        /// Start index.
        dimension_size_type     begin;
        /// End index.
        dimension_size_type     end;
      };

      /// Mapping between series index and IFD range.
      typedef std::vector<IFDRange> SeriesIFDRange;

      /**
       * Compute IFD index from IFD map and plane index.
       *
       * @param seriesIFDRange the series--IFD range mapping.
       * @param series the series to use.
       * @param plane the plane within the series to use.
       * @param sizeC the number of channels in the series.
       * @param isRGB the number of subchannels in the series.
       * @returns the IFD index.
       */
      dimension_size_type
      ifdIndex(const SeriesIFDRange& seriesIFDRange,
               dimension_size_type   series,
               dimension_size_type   plane,
               dimension_size_type   sizeC,
               bool                  isRGB);

    }
  }
}

#endif // OME_BIOFORMATS_TIFF_UTIL_H

/*
 * Local Variables:
 * mode:C++
 * End:
 */
